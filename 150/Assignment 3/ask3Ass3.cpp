
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <Graph.h>
#include <GUI.h>
#include <Window.h>

using namespace Graph_lib;
using namespace std;

const char number = '8';
const char quit   = 'q';
const char print  = ';';
const char name   = 'a';
const char let    = 'L';
const string declkey = "let";
stringstream ss;
stringstream res;
stringstream err;

class Token {
public:
    char kind;
    double value;
    string name;
    Token(char ch)             : kind(ch), value(0)   {}
    Token(char ch, double val) : kind(ch), value(val) {}
    Token(char ch, string n)   : kind(ch), name(n)    {}
};


class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);
    void ignore(char c);
private:
    bool full;
    Token buffer;
};


Token_stream::Token_stream()
    : full(false), buffer(0)
{
}


void Token_stream::putback(Token t)
{
    if (full) {
        err << "Putback() into a full buffer";
        error("putback() into a full buffer");
    }
    buffer = t;
    full = true;
}


Token Token_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    ss >> ch;   // Taking tokens from the stringstream and not from the cin

    switch (ch) {
    case print:
    case quit:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '=':
        return Token(ch);
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        ss.putback(ch);     // again using the stringstream
        double val;
        ss >> val;
        return Token(number, val);
    }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (ss.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
            ss.putback(ch);
            if (s == declkey) return Token(let);
            return Token(name, s);
        }
        err << "Bad token";
        error("Bad token");
    }
}


void Token_stream::ignore(char c)

{

    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while (ss >> ch)
        if (ch == c) return;
}


Token_stream ts;


class Variable {
public:
    string name;
    double value;
    Variable (string n, double v) : name(n), value(v) { }
};


vector<Variable> var_table;


double get_value(string s)

{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    err << "Undefined variable " << s;
    error("get: undefined variable ", s);

}


void set_value(string s, double d)

{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) {
            var_table[i].value = d;
            return;
        }
    err << "Undefined variable " << s;
    error("set: undefined variable ", s);
}


bool is_declared(string var)

{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == var) return true;
    return false;
}


double define_name(string var, double val)

{
    if (is_declared(var)) {
        err << var << " declared twice";
        error(var, " declared twice");
    }
    var_table.push_back(Variable(var, val));
    return val;
}


double expression();


double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') {
            err << "')' expeted";
            error("')' expected");
        }
        return d;
    }
    case number:
        return t.value;
    case name:
        return get_value(t.name);
    case '-':
        return - primary();
    case '+':
        return primary();
    default:
        err << "Primary expected";
        error("primary expected");
    }
}


double term()
{
    double left = primary();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) {
                err << "Divide by zero";
                error("divide by zero");
            }
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            int i1 = narrow_cast<int>(left);
            int i2 = narrow_cast<int>(term());
            if (i2 == 0) {
                err << "Divide by zero";
                error("%: divide by zero");
            }
            left = i1 % i2;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}


double expression()
{
    double left = term();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}


double declaration()

{
    Token t = ts.get();
    if (t.kind != name) {
        err << "Name expected in declaration";
        error ("name expected in declaration");
    }
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') {
        err << "= missing in declaration of " << var_name;
        error("= missing in declaration of ", var_name);
    }
    double d = expression();
    define_name(var_name, d);
    return d;
}


double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}


void clean_up_mess()
{
    ts.ignore(print);
}


void calculate()
{
    while (!ss.eof())   // loop till the end of the stream
        try {
            Token t = ts.get();
            while (t.kind == print) t = ts.get();
            if (t.kind == quit) return;
            ts.putback(t);
            res << statement();
        }
        catch (exception& e) {
            cerr << e.what() << endl;
            clean_up_mess();
        }
}

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title );
private:

    Open_polyline lines;


    Button next_button;
    Button quit_button;
    In_box equation;
    Out_box xy_out;
    Out_box err_out;
    void next();
    void quit();


    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
};


Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    : Window(xy, w, h, title),
      next_button(Point(320, 60), 100, 20, "Find Result", cb_next),
      quit_button(Point(320, 100), 100, 20, "Quit", cb_quit),
      equation(Point(100, 40), 200, 20, "Equation:"),
      xy_out(Point(100, 80), 200, 20, "Result:"),
      err_out(Point(100, 120), 200, 20, "Error:") // New box with the errors
{
    attach(next_button);
    attach(quit_button);
    attach(equation);
    attach(xy_out);
    attach(err_out);    // Attaching the new box
}


void Lines_window::cb_quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit();
}


void Lines_window::quit()
{
    hide();
}


void Lines_window::cb_next(Address, Address pw)
{
    reference_to<Lines_window>(pw).next();
}


void Lines_window::next()
{
    string x = equation.get_string();   // Get the text the user typed inside the equation box as a string
    ss << x << ";q";    // Inserting the string inside the stringstream with ;q at the end were ; means print result and q quit the calculator
    calculate();
    xy_out.put(res.str());  // Giving the results at the boxes
    err_out.put(err.str());
    res.str("");    // Clearing the stringstreams
    err.str("");
    redraw();
}

int main()
try {
    Lines_window win(Point(100, 100), 500, 200, "Calculator");
    return gui_main();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}


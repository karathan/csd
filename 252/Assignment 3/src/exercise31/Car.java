/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise31;

/**
 *
 * 
 */
public class Car {
    private String name;
    private String manufacturer;
    private String country;
    /**
     * Top speed in kilometers per hour (km/h)
     */
    private int topSpeed;
    /**
     * Time in seconds from 0 to 100 km/h
     */
    private double acceleration;
    private int year;
    
    @Override
    public String toString() {
        return "Name: "+name+"\nManufacturer: "+manufacturer+"\nCountry: "+country+"\nTop speed: "+topSpeed+"\nAcceleration: "+acceleration+"\nYear: "+year+"\n";
    }
    
    public Car() {
        
    }

    public Car(String name, String manufacturer, String country, int topSpeed, double acceleration, int year) {
        this.name = name;
        this.manufacturer = manufacturer;
        this.country = country;
        this.topSpeed = topSpeed;
        this.acceleration = acceleration;
        this.year = year;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    public void setManufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
    }

    public String getCountry() {
        return country;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public int getTopSpeed() {
        return topSpeed;
    }

    public void setTopSpeed(int topSpeed) {
        this.topSpeed = topSpeed;
    }

    public double getAcceleration() {
        return acceleration;
    }

    public void setAcceleration(double acceleration) {
        this.acceleration = acceleration;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }
      
    
}
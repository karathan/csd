/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise31;

/**
 *
 * @author mitsos
 * @param <P>
 */
public interface CarFactory<P extends Car> {

    P create(String name, String manufacturer, String country, int topSpeed, double acceleration, int year);

}

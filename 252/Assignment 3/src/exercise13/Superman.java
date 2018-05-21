/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercise13;

import exercise11.iFly;

/**
 *
 * @author mitsos
 */
public class Superman implements iFly, iHero2 {
    
    @Override
    public void run(){
        iHero2.super.run();
    }
    
}

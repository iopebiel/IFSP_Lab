/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.prjcalculadora;

/**
 *
 * @author aluno
 */
public class PrjCalculadora {

    public static void main(String[] args) {
        
        Calculadora oCalculadora = new Calculadora(10, 5);
        
        
        System.out.println("Soma de "+ oCalculadora.getValor1() + " por " + oCalculadora.getValor2() + " = " + oCalculadora.soma());
        System.out.println("Substração de "+ oCalculadora.getValor1() + " por " + oCalculadora.getValor2() + " = " + oCalculadora.subtracao());
        System.out.println("Multiplicação de "+ oCalculadora.getValor1() + " por " + oCalculadora.getValor2() + " = " + oCalculadora.multiplicacao());
        System.out.println("Divisão de "+ oCalculadora.getValor1() + " por " + oCalculadora.getValor2() + " = " + oCalculadora.divisao());
    }
}

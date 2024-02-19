/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prjcalculadora;

/**
 *
 * @author aluno
 */
public class Calculadora {
    
    private double valor1;
    private double valor2;

    public Calculadora() {    
    }
    
    public Calculadora(double valor1, double valor2) {
        this.valor1 = valor1;
        this.valor2 = valor2;
    }

    public double getValor1() {
        return valor1;
    }

    public void setValor1(double vvalor1) {
        this.valor1 = vvalor1;
    }

    public double getValor2() {
        return valor2;
    }

    public void setValor2(double vvalor2) {
        this.valor2 = vvalor2;
    }
    
    
    public double soma () {
        return (valor1 + valor2);
    }

    public double subtracao () {
        return (valor1 - valor2);
    }

    public double multiplicacao () {
        return (valor1 * valor2);
    }

    public double divisao () {
        return (valor1 / valor2);
    }
}

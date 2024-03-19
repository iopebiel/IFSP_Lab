/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.aluno;

/**
 *
 * @author aluno
 */
public class Telefone {
    private String ddd;
    private String numero;

    public Telefone(String ddd, String numero) {
        this.ddd = ddd;
        this.numero = numero;
    }

    public String getNumero() {
        return ddd + " " + numero;
    }

    public void setNumero(String ddd, String numero) {
        this.ddd = ddd;
        this.numero = numero;
    }
    
}

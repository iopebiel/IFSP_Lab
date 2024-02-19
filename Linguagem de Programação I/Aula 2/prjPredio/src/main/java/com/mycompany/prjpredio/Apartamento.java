/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prjpredio;

/**
 *
 * @author aluno
 */
public class Apartamento {
    private int numero;
    private int andar;
    private Morador morador;

    public Apartamento() {
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int pNumero) {
        this.numero = pNumero;
    }

    public int getAndar() {
        return andar;
    }

    public void setAndar(int pAndar) {
        this.andar = pAndar;
    }

    public Morador getMorador() {
        return morador;
    }

    public void setMorador(Morador pMorador) {
        this.morador = pMorador;
    }
    
    
    
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prjpredio;

/**
 *
 * @author aluno
 */
public class Bloco {
    private String nome;
    private int quantidadeAndares;
    private boolean cobertura;
    private Apartamento apartamento;

    public Bloco() {
    }
    
    public void setNome(String pNome){
        this.nome = pNome;
    }
    public String getNome(){
        return this.nome;
    }

    public int getQuantidadeAndares() {
        return quantidadeAndares;
    }

    public void setQuantidadeAndares(int pQuantidadeAndares) {
        this.quantidadeAndares = pQuantidadeAndares;
    }

    public boolean isCobertura() {
        return cobertura;
    }

    public void setCobertura(boolean pCobertura) {
        this.cobertura = pCobertura;
    }
    
    public Apartamento getApartamento() {
        return apartamento;
    }

    public void setApartamento(Apartamento pApartamento) {
        this.apartamento = pApartamento;
    }
    
    
    
}

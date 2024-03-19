/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prjempresa;

/**
 *
 * @author aluno
 */
public class Empresa {
    
    private String nome;
    private int qtdFunc;

    public Empresa() {
    }

    public Empresa(String nome, int qtdFunc) {
        this.nome = nome;
        this.qtdFunc = qtdFunc;
    }
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getQtdFunc() {
        return qtdFunc;
    }

    public void setQtdFunc(int qtdFunc) {
        this.qtdFunc = qtdFunc;
    }
    
    
}

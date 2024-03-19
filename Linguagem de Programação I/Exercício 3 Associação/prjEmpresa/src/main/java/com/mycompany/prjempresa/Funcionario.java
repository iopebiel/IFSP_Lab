/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prjempresa;

/**
 *
 * @author aluno
 */
public class Funcionario {
    private String nome;
    private double salBruto;
    private boolean PJ;
    private Empresa empresa;

    public Funcionario() {
    }

    public Funcionario(String nome, double salBruto, boolean PJ, Empresa empresa) {
        this.nome = nome;
        this.salBruto = salBruto;
        this.PJ = PJ;
        this.empresa = empresa;
    }

    
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getSalBruto() {
        return salBruto;
    }

    public void setSalBruto(double salBruto) {
        this.salBruto = salBruto;
    }

    public boolean isPJ() {
        return PJ;
    }

    public void setPJ(boolean PJ) {
        this.PJ = PJ;
    }

    public Empresa getEmpresa() {
        return empresa;
    }

    public void setEmpresa(Empresa empresa) {
        this.empresa = empresa;
    }
    
    public double getSalario(int pQtdFunc) {
        if (PJ == true) {
            return (salBruto * 0.8 - 0.01 * pQtdFunc);
        } else {
            return (salBruto * 0.9 - 0.02 * pQtdFunc);
        }
    }
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prjnotafiscal;

/**
 *
 * @author aluno
 */
public class Item {
    private int numero;
    private int quantidade;
    protected Produto produto;

    public Item() {
    }

    public Item(int numero, int quantidade, Produto produto) {
        this.numero = numero;
        this.quantidade = quantidade;
        this.produto = produto;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public Produto getProduto() {
        return produto;
    }

    public void setProduto(Produto produto) {
        this.produto = produto;
    }
    
    
}

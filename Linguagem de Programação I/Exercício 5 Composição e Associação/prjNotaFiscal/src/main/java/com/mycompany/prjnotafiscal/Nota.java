/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.prjnotafiscal;

/**
 *
 * @author aluno
 */
import java.util.ArrayList;

public class Nota {
    private int numero;
    private String date;
    protected Cliente cliente;
    protected ArrayList<Item> item;

    public Nota() {
    }

    public Nota(int numero, String date, Cliente cliente, ArrayList<Item> item) {
        this.numero = numero;
        this.date = date;
        this.cliente = cliente;
        this.item = item;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public ArrayList<Item> getItens() {
        return item;
    }
    public Item getItem(int i) {
        return item.get(i);
    }

    public void setItem(ArrayList<Item> item) {
        this.item = item;
    }
}

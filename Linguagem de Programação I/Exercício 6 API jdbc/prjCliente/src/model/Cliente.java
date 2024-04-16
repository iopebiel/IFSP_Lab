/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model;

/**
 *
 * @author ubuntu-user
 */
public class Cliente {
    private int id;
    private String nome;
    private String endereco;
    private int idade;
    
    //SELECT *
    public Cliente () {
    }
    
    //INSERT
    public Cliente(String pn, String pe, int pi) {
        this.nome = pn;
        this.endereco = pe;
        this.idade = pi;
    }    

    //UPDATE
    public Cliente(int pid, String pn, String pe, int pi) {
        this.id = pid;
        this.nome = pn;
        this.endereco = pe;
        this.idade = pi;
    }
    
    //DELETE / SELECT WHERE;
    public Cliente(int pid) {
        this.id = pid;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }
    
}

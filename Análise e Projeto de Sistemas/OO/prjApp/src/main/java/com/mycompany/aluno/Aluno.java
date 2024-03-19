/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.aluno;

import java.util.ArrayList;
/**
 *
 * @author aluno
 */
public class Aluno {
    private long prontuario;
    private String nome;
    private Email email;
    private ArrayList<Telefone> telefones = new ArrayList<>();
    
    public void inserirTelefone(Telefone telefone) {
        if (telefones.size() > 1) {
            System.out.println("\nNúmero: " + telefone.getNumero() + " Não foi incluído");
            System.out.println("Número de Telefone excedido! \n" + telefones.size() + " telefones cadastrados\n");
        }
        else{
            boolean add = this.telefones.add(telefone);
                if (add == true)
                    System.out.println("Telefone adicionado com sucesso!\n");
                else
                    System.out.println("Erro! telefone não incluído.\n");
        }
    }

    public Aluno(long prontuario, String nome, Telefone telefone) {
        this.prontuario = prontuario;
        this.nome = nome;
        this.telefones.add(telefone);
    }

    public long getProntuario() {
        return prontuario;
    }

    public void setProntuario(long prontuario) {
        this.prontuario = prontuario;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Email getEmail() {
        return email;
    }

    public void setEmail(Email email) {
        this.email = email;
    }
    
    public ArrayList<Telefone> getTelefones() {
        return telefones;
    }
    
    public Telefone getTelefone(int i) {
        return telefones.get(i);
    }

    public void setTelefones(Telefone telefone) {
        this.telefones.add(telefone);
    }
    
    
}

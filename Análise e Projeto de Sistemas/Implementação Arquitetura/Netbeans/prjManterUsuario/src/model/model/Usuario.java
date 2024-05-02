/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model.model;

/**
 *
 * @author ubuntu-user
 */
public class Usuario {
    private int id;
    private String nome;
    private String prontuario;
    private String dataNascimento;
    
    //SELECT *
    public Usuario () {
    }
    
    //INSERT
    public Usuario(String pNome, String pProntuario, String pData) {
        this.nome = pNome;
        this.prontuario = pProntuario;
        this.dataNascimento = pData;
    }    

    //UPDATE
    public Usuario(int pId, String pNome, String pProntuario, String pData) {
        this.id = pId;
        this.nome = pNome;
        this.prontuario = pProntuario;
        this.dataNascimento = pData;
    }    
    
    //DELETE / SELECT WHERE;
    public Usuario(int pId) {
        this.id = pId;
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

    public String getProntuario() {
        return prontuario;
    }

    public void setProntuario(String prontuario) {
        this.prontuario = prontuario;
    }

    public String getDataNascimento() {
        return dataNascimento;
    }

    public void setDataNascimento(String dataNascimento) {
        this.dataNascimento = dataNascimento;
    }
    
}

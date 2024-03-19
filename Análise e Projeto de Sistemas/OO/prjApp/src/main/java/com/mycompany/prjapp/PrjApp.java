/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.prjapp;

import com.mycompany.aluno.Aluno;
import com.mycompany.aluno.Email;
import com.mycompany.aluno.Telefone;

/**
 *
 * @author aluno
 */
public class PrjApp {
    
    private static PrjApp app;
    
    public static void main(String[] args) {
        
        app = new PrjApp();
        Aluno aluno = app.criarAluno("Gabriel Iope", 1L, "gabriel.r.iope@gmail.com", "11", "94084-2308");
        app.saida(aluno);
        app.imprimirDados(aluno);
    }
   
    public Email criarEmail(String email) {
        return new Email(email);
    }
    
    public Telefone criarTelefone (String ddd, String numero) {
        return new Telefone(ddd, numero);
    }
    
    public void saida(Aluno aluno) {
        System.out.println("Aluno " + aluno.getNome() + " criado com sucesso!\n");
    }
    
    public Aluno criarAluno(String nome, long prontuario, String email, String ddd, String numero) {
        Aluno aluno = new Aluno(prontuario, nome, criarTelefone(ddd, numero));
        
        aluno.setEmail(criarEmail(email));
        aluno.inserirTelefone(criarTelefone("11", "94768-2378"));
        aluno.inserirTelefone(criarTelefone("11", "94722-9089"));
        
        return aluno;
    }
    
    public void imprimirDados(Aluno aluno) {
        System.out.println("ALUNO");
        System.out.println("Prontuário: " + aluno.getProntuario());
        System.out.println("Nome: " + aluno.getNome());
        
        System.out.println("\nINFORMAÇÕES DE CONTATO");
        System.out.println("E-mail: " + aluno.getEmail().getEmail());
        
        for(int x = 0; x < aluno.getTelefones().size(); x++)
        {
            System.out.println("Telefone " + (x+1) + ": " + aluno.getTelefone(x).getNumero());
        }
    }
   
}

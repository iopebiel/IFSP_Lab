/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package view.usuario;

import java.util.Scanner;
import java.sql.SQLException;
import model.model.Usuario;
import view.controller.ManterUsuarioBean;
/**
 *
 * @author Gabriel Iope
 */
public class PrjManterUsuario {

    public static void main(String[] args) throws SQLException {
        Scanner scan = new Scanner(System.in);
        
        int id;
        String nome;
        String prontuario;
        String dataNascimento;
        ManterUsuarioBean usuarioBean;
        Usuario usuario;
        
        int opcao = 0;
        do {
            
            System.out.println("ESCOLHA UMA AÇÃO:");
            System.out.println("1- Cadastrar");
            System.out.println("2- Remover");
            System.out.println("3- Atualizar");
            System.out.println("4- Encerrar\n");
        
            
            opcao = scan.nextInt();

            switch (opcao) {
                case 1:                       
                       System.out.println("\nDigite o número de ID para inserir: ");
                       id = scan.nextInt();
                       scan.nextLine();
                       System.out.println("Digite o nome: ");
                       nome = scan.nextLine();
                       System.out.println("Digite o Prontuário: ");
                       prontuario = scan.nextLine();
                       System.out.println("Digite a Data de Nascimento(dd/mm/yyyy): ");
                       dataNascimento = scan.nextLine();
                       usuarioBean = new ManterUsuarioBean();
                       usuarioBean.setUsuario(new Usuario(id, nome, prontuario, dataNascimento));
                       usuarioBean.inserir();
                       break;
                case 2:
                       System.out.println("\nDigite o número de ID para remover: ");
                       id = scan.nextInt();
                       scan.nextLine();
                       usuarioBean = new ManterUsuarioBean();
                       usuarioBean.setUsuario(new Usuario(id));
                       usuarioBean.remover();
                       break;
                case 3:
                       System.out.println("\nDigite o número de ID para atualizar: ");
                       id = scan.nextInt();
                       scan.nextLine();
                       System.out.println("Digite o nome: ");
                       nome = scan.nextLine();
                       System.out.println("Digite o Prontuário: ");
                       prontuario = scan.nextLine();
                       System.out.println("Digite a Data de Nascimento(dd/mm/yyyy): ");
                       dataNascimento = scan.nextLine();
                       usuarioBean = new ManterUsuarioBean();
                       usuarioBean.setUsuario(new Usuario(id, nome, prontuario, dataNascimento));
                       usuarioBean.atualizar();
                       break;
                case 4: 
                        break;
            }
            
        } while (opcao != 4);
    
    }
}

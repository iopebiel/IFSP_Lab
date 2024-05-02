/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package view.controller;

import java.sql.SQLException;
import java.util.ArrayList;
import controller.service.UsuarioService;
import model.model.Usuario;

/**
 *
 * @author ubuntu-user
 */
public class ManterUsuarioBean {
    private UsuarioService uService;
    private ArrayList<Usuario> tabela;
    private Usuario usuario;

    public ManterUsuarioBean() throws SQLException {
        usuario = new Usuario();
        uService = new UsuarioService(usuario);
        atualizarUsuarios();
    }

    public final void atualizarUsuarios() throws SQLException {
       uService = new UsuarioService(usuario);
       tabela = uService.listar();
    }
    

    public void inserir() throws SQLException {
        uService = new UsuarioService(usuario);
        System.out.println(uService.inserir());
        atualizarUsuarios();
        uService = new UsuarioService();
        listar();
        
    }
    
    public void remover() throws SQLException {
        uService = new UsuarioService(usuario);
        System.out.println(uService.remover());
        atualizarUsuarios();
        uService = new UsuarioService();
        listar();
    }
    
    public void atualizar() throws SQLException {
        uService = new UsuarioService(usuario);
        System.out.println(uService.atualizar());
        atualizarUsuarios();
        uService = new UsuarioService();
        listar();
    }

    public void listar() throws SQLException {
        uService = new UsuarioService(usuario);
        atualizarUsuarios();
        if (tabela.isEmpty() != true) {
            for (int i = 0; i < tabela.size(); i++)
            {
                System.out.println("\nId: " + tabela.get(i).getId());
                System.out.println("Nome: " + tabela.get(i).getNome());
                System.out.println("Prontuário: " + tabela.get(i).getProntuario());
                System.out.println("Data Nascimento: " + tabela.get(i).getDataNascimento() + "\n");
            }
        } else {
        }
    }
    public ArrayList<Usuario> getTabela() {
        return tabela;
    }

    public void setTabela(ArrayList<Usuario> tabela) {
        this.tabela = tabela;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }
    
    
    
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller.service;

import java.sql.SQLException;
import java.util.ArrayList;
import model.dao.UsuarioDAO;
import model.model.Usuario;
/**
 *
 * @author ubuntu-user
 */
public class UsuarioService {
    private Usuario usuario;
    private UsuarioDAO dao;

    public UsuarioService() {
    }

    public UsuarioService(Usuario usuario) throws SQLException {
        this.usuario = usuario;
        this.dao = new UsuarioDAO(this.usuario);
    }

    public String inserir() throws SQLException {
        return ((this.dao.inserir() == true) ? "\nUsuário inserido com sucesso!\n" : "\nErro ao inserir Usuário!\n");
    }
    
    public String remover() throws SQLException {
        return ((this.dao.remover()== true) ? "\nUsuário removido com sucesso!\n" : "\nErro ao remover Usuário!\n");
    }
    
    public String atualizar() throws SQLException {
        return ((this.dao.atualizar()== true) ? "\nDados de Usuário atualizado com sucesso!\n" : "\nErro ao atualizar dados do Usuário!\n");
    }
    
    public ArrayList<Usuario> listar() {
        try {
            return this.dao.listar();
        } catch (SQLException e) {
            return null;
        }
    }
}

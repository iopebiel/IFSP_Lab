/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.SQLException;
import java.util.ArrayList;
import model.model.Usuario;
/**
 *
 * @author ubuntu-user
 */
public class UsuarioDAO {
    private Connection con; //Conexão com o banco.
    private PreparedStatement cmd; //Cmd para aplicar comandos SQL.
    private Usuario usuario;

    public UsuarioDAO(Usuario usuario)throws SQLException{
        this.con = Conexao.Conectar();
        this.usuario = usuario;

        this.con.setAutoCommit(false); //Não realizar commit automático.
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }
    
    
    public boolean inserir() throws SQLException {
        try {
            String sql = "INSERT INTO usuario (id, nome, prontuario, dataNascimento) VALUES (?, ?, ?, ?);";
            cmd = con.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            cmd.setInt(1, this.usuario.getId());
            cmd.setString(2, this.usuario.getNome());
            cmd.setString(3, this.usuario.getProntuario());
            cmd.setString(4, this.usuario.getDataNascimento());
            if (cmd.executeUpdate() > 0) {
                con.commit();
                return true;
            } else {
                con.rollback();
                return false;
            }
           
        } catch (SQLException e) {
            con.rollback();
            return false;
        } finally { Conexao.Desconectar(con); }
    }
    
    public boolean remover() throws SQLException {
        try {
            String sql = "DELETE FROM usuario WHERE id = ?";
            cmd = con.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            cmd.setInt(1, this.usuario.getId());
            if (cmd.executeUpdate() > 0) {
                con.commit();
                return true;
            } else {
                con.rollback();
                return false;
            }
           
        } catch (SQLException e) {
            con.rollback();
            return false;
        } finally { Conexao.Desconectar(con); }
    }
    
    
    public boolean atualizar() throws SQLException {
        try {
            String sql = "UPDATE usuario SET nome = ?, prontuario = ?, dataNascimento = ? WHERE id = ?;";
            cmd = con.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            cmd.setString(1, this.usuario.getNome());
            cmd.setString(2, this.usuario.getProntuario());
            cmd.setString(3, this.usuario.getDataNascimento());
            cmd.setInt(4, this.usuario.getId());
                                                
            if (cmd.executeUpdate() > 0) {
                con.commit();
                return true;
            } else {
                con.rollback();
                return false;
            }
           
        } catch (SQLException e) {
            con.rollback();
            return false;
        } finally { Conexao.Desconectar(con); }
    }
    
    public ArrayList<Usuario> listar() throws SQLException{
        try {
            String sql = "SELECT id, nome, prontuario, dataNascimento FROM usuario;";
            cmd = con.prepareStatement(sql);
            ResultSet rs = this.cmd.executeQuery();
            ArrayList<Usuario> lista = new ArrayList<>();
            while (rs.next()) {
                Usuario usu_temp = new Usuario();
                
                usu_temp.setId(rs.getInt("id"));
                usu_temp.setNome(rs.getString("nome"));
                usu_temp.setProntuario(rs.getString("prontuario"));
                usu_temp.setDataNascimento(rs.getString("dataNascimento"));
                
                lista.add(usu_temp);
            }
            
            return lista;
        } catch (SQLException e) {
            System.out.println("ERRO: " + e);
            return null;
        } finally { Conexao.Desconectar(con); }
    }
    
    public Usuario listar(boolean chave) {
        try {    
            String sql = "SELECT id, nome, prontuario, dataNascimento FROM usuario WHERE id = ?;";
            cmd = con.prepareStatement(sql);
            cmd.setInt(1, this.usuario.getId());
            ResultSet rs = this.cmd.executeQuery();
            
            Usuario usuario = new Usuario();
            
            while (rs.next()) {
                Usuario usu_temp = new Usuario();
                
                usu_temp.setId(rs.getInt("id"));
                usu_temp.setNome(rs.getString("nome"));
                usu_temp.setProntuario(rs.getString("prontuario"));
                usu_temp.setDataNascimento(rs.getString("data de nascimento"));
                
                usuario = usu_temp;
            }
            
            return usuario;
        } catch (SQLException e) {
            System.out.println("ERRO: " + e);
            return null;
        } finally { Conexao.Desconectar(con); }    }
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
/**
 *
 * @author ubuntu-user
 */
public class ClienteDAO {
    private Connection con; //Conexão com o banco.
    private PreparedStatement cmd; //Cmd para aplicar comandos SQL.
    private Cliente cli;

    public ClienteDAO(Cliente cli)throws SQLException{
        this.cli = cli;
        this.con = Conexao.Conectar();
        this.con.setAutoCommit(false); //Não realizar commit automático.
    }

    public void setCliente(Cliente cli) {
        this.cli = cli;
    }
    
    
    public boolean inserir() throws SQLException {
        try {
            String sql = "INSERT INTO cliente (nome, endereco, idade) VALUES (?, ?, ?);";
            cmd = con.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            cmd.setString(1, this.cli.getNome());
            cmd.setString(2, this.cli.getEndereco());
            cmd.setInt(3, this.cli.getIdade());
            if (cmd.executeUpdate() > 0) {
                con.commit();
                return true;
            } else {
                con.rollback();
                return false;
            }
           
        } catch (Exception e) {
            con.rollback();
            return false;
        } finally { Conexao.Desconectar(con); }
    }
    
    public boolean remover() throws SQLException {
        try {
            String sql = "DELETE FROM cliente WHERE id = ?";
            cmd = con.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            cmd.setInt(1, this.cli.getId());
            if (cmd.executeUpdate() > 0) {
                con.commit();
                return true;
            } else {
                con.rollback();
                return false;
            }
           
        } catch (Exception e) {
            con.rollback();
            return false;
        } finally { Conexao.Desconectar(con); }
    }
    
    
    public boolean atualizar() throws SQLException {
        try {
            String sql = "UPDATE cliente SET nome = ?, endereco = ?, idade = ? WHERE id = ?";
            cmd = con.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            cmd.setString(1, this.cli.getNome());
            cmd.setString(2, this.cli.getEndereco());
            cmd.setInt(3, this.cli.getIdade());
            cmd.setInt(4, this.cli.getId());
                                                
            if (cmd.executeUpdate() > 0) {
                con.commit();
                return true;
            } else {
                con.rollback();
                return false;
            }
           
        } catch (Exception e) {
            con.rollback();
            return false;
        } finally { Conexao.Desconectar(con); }
    }
    
    
}

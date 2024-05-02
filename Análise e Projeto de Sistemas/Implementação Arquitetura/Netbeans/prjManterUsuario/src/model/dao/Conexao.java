/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
/**
 *
 * @author ubuntu-user
 */
public class Conexao {
    private static final String DATABASE = "aps"; //Banco de dados.
    private static final String HOST = "localhost:3306"; //endereço do servidor
    private static final String DRIVER = "com.mysql.cj.jdbc.Driver"; //pacote
    private static final String URL = "jdbc:mysql://" + HOST + "/" + DATABASE; //URL Completa para acessar o banco de dados.          
    private static final String USR = "root"; //Usuário do banco de dados.
    private static final String PWD = ""; //Senha.
    
    
    public static Connection Conectar() {
        try {
            Class.forName(DRIVER);
            return DriverManager.getConnection(URL, USR, PWD);
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println("ERRO: " + e.getMessage());
            return null;
        }
    }

    public static void Desconectar(Connection con) {
        try {
            if (con != null) {
                con.close();
            }
        } catch (SQLException e) {
            System.out.println("ERRO: " + e.getMessage());
        }
    }

}

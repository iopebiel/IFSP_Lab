/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package view;

import model.Conexao;
import java.sql.Connection;

/**
 *
 * @author ubuntu-user
 */
public class PrjCliente {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Connection con = Conexao.Conectar();
        if (con != null) {
            System.out.println("Conexão OK");
            Conexao.Desconectar(con);
        }
    }
    
}

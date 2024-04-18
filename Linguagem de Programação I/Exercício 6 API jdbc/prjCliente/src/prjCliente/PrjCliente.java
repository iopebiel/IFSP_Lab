/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package prjCliente;

import controller.ClienteC;
import model.Cliente;
import java.sql.SQLException;
/**
 *
 * @author ubuntu-user
 */
public class PrjCliente {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws SQLException {
        System.out.println(new ClienteC(new Cliente("Sabrina Lopes", "Jardim Três Marias", 20)).inserir());
        System.out.println(new ClienteC(new Cliente(1,"João", "Jardim Três Marias, Salto - SP", 25)).atualizar());
        System.out.println(new ClienteC(new Cliente(3)).remover());
         
    }   
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package view;

import model.ClienteDAO;
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
            //INSERT INTO
            ClienteDAO dao = new ClienteDAO(new Cliente("Gabriel Roque Iope", "Nações, Salto - SP", 20));
            System.out.println("Inserido com sucesso? " + dao.inserir());
            
            //UPDATE
            ClienteDAO dao1 = new ClienteDAO(new Cliente(3, "João Camargo Miranda", "São Pedro São Paulo, Salto - SP", 22));
            System.out.println("Atualizado com sucesso? " + dao1.atualizar() );
            ClienteDAO dao2 = new ClienteDAO(new Cliente(4, "Flávia Lessandra", "Jardim Donalísio, Salto - SP", 20));
            System.out.println("Atualizado com sucesso? " + dao2.atualizar() );
            
            //DELETE
            ClienteDAO dao3 = new ClienteDAO(new Cliente(5));
            System.out.println("Removido com sucesso? " + dao3.remover());            
         
    }   
}

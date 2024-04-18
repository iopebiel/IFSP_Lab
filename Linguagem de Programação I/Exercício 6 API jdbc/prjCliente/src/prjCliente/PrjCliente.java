/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package prjCliente;

import java.sql.SQLException;

import view.frmCadastro;
/**
 *
 * @author ubuntu-user
 */
public class PrjCliente {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws SQLException {
        
        frmCadastro form = new frmCadastro();
        form.setVisible(true);
        
    }   
}

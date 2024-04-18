/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller;

import java.sql.SQLException;
import model.Cliente;
import model.ClienteDAO;
/**
 *
 * @author ubuntu-user
 */
public class ClienteC {
    private Cliente cliente;
    private ClienteDAO dao;

    public ClienteC() {
    }

    public ClienteC(Cliente cliente) throws SQLException {
        this.cliente = cliente;
        this.dao = new ClienteDAO(this.cliente);
    }

    public String inserir() throws SQLException {
        return ((dao.inserir() == true) ? "Cliente inserido com sucesso!" : "Erro ao inserir Cliente!");
    }
    
    public String remover() throws SQLException {
        return ((dao.remover()== true) ? "Cliente removido com sucesso!" : "Erro ao remover Cliente!");
    }
    
    public String atualizar() throws SQLException {
        return ((dao.atualizar()== true) ? "Dados de Cliente atualizado com sucesso!" : "Erro ao atualizar dados do Cliente!");
    }
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package model;

import java.sql.SQLException;
/**
 *
 * @author ubuntu-user
 */
public interface Idml {
    
    public boolean inserir() throws SQLException;
    public boolean remover() throws SQLException;
    public boolean atualizar() throws SQLException;
}

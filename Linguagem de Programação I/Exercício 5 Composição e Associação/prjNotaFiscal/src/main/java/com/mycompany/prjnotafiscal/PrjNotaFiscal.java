/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.prjnotafiscal;

/**
 *
 * @author aluno
 */
import java.util.ArrayList;
public class PrjNotaFiscal {

    public static void main(String[] args) {
        Cliente oCliente = new Cliente("Gabriel", "53802281861");
        
        Produto oProduto = new Produto(1,"iPhone X", 1500.00);
        Item oItem = new Item(1, 2, oProduto);
        
        Produto oProduto2 = new Produto(2,"TV LG", 2800.00);
        Item oItem2 = new Item(2, 4, oProduto2);
        
       
        ArrayList<Item> ListItem = new ArrayList<Item>();
        ListItem.add(oItem);
        ListItem.add(oItem2);
        
        Nota oNota = new Nota(1, "11/03/2024", oCliente, ListItem);
        
        System.out.println("NOTA FISCAL Nº " + oNota.getNumero());
        System.out.println("Data: " + oNota.getDate());
        
        System.out.println("\nCLIENTE:");
        System.out.println("Nome: " + oNota.getCliente().getNome()); 
        System.out.println("CPF: " + oNota.getCliente().getCPF() + "\n");
        System.out.println("LISTA DE ITENS:\n");
        for (int i = 0; i < oNota.getItens().size(); i++) 
        {
            System.out.println("Item de código " + oNota.getItem(i).getProduto().getCodigo() + " : " + oNota.getItem(i).getProduto().getDescricao());
            System.out.println("Valor: " + oNota.getItem(i).getProduto().getValor());
            System.out.println("Quantidade: " + oNota.getItem(i).getQuantidade() + "\n");
        }
    }
}

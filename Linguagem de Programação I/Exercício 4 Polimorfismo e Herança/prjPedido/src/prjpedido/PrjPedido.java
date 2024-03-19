/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package prjpedido;

/**
 *
 * @author aluno
 */
public class PrjPedido {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Perecivel oPerecivel = new Perecivel("25/02/2024", "Salto", 1, "Arroz", 29.50);
        Permanente oPermanente = new Permanente(0.05, false, 2, "Panela Tramontina", 60.70);
        
        Pedido oPedido = new Pedido(20,"10/01/2024", 3, oPerecivel);
        
        Pedido oPedido2 = new Pedido(21,"15/01/2024", 2, oPermanente);
        
        System.out.println("pedido de " + oPedido.getoProduto().getDescricao() + " sairá por R$" +oPedido.calcValorTotal());
        System.out.println("pedido de " + oPedido2.getoProduto().getDescricao() + " sairá por R$" +oPedido2.calcValorTotal());
    }
    
}

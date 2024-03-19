/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.prjpredio;

/**
 *
 * @author aluno
 */

import java.util.Scanner;

public class PrjPredio {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        Morador oMorador = new Morador();
        
        System.out.println("Qual o nome do morador: ");
        oMorador.setNome(scan.nextLine());
        
        System.out.println("Qual a idade do morador: ");
        oMorador.setIdade(scan.nextInt());
        
        
        Apartamento oApartamento = new Apartamento();
        
        System.out.println("Qual o número do apartamento: ");
        oApartamento.setNumero(scan.nextInt());
        
        System.out.println("Qual o andar do apartamento: ");
        oApartamento.setAndar(scan.nextInt());
        
        oApartamento.setMorador(oMorador);
        
        Bloco oBloco = new Bloco();
        
        System.out.println("Qual o nome do bloco: ");
        oBloco.setNome(scan.next());
        
        System.out.println("Qual a quantidade de andares no bloco: ");
        oBloco.setQuantidadeAndares(scan.nextInt());
        
        System.out.println("Tem cobertura? ");
        oBloco.setCobertura(scan.nextBoolean());
                
        oBloco.setApartamento(oApartamento);
        
        
        System.out.println("=======dados cadastrados========");
        
        System.out.println("-----Morador");
        System.out.println("Nome: " + oBloco.getApartamento().getMorador().getNome());
        System.out.println("Idade: " + oBloco.getApartamento().getMorador().getIdade());
        System.out.println("-----Apartamento");
        System.out.println("Número: " + oBloco.getApartamento().getNumero());
        System.out.println("Andar: " + oBloco.getApartamento().getAndar());
        System.out.println("-----Bloco");
        System.out.println("Nome: " +  oBloco.getNome());
        System.out.println("Quantidade de Andares: " + oBloco.getQuantidadeAndares());
        System.out.println("Tem cobertura? " + oBloco.isCobertura());
        
        scan.close();
    }
}

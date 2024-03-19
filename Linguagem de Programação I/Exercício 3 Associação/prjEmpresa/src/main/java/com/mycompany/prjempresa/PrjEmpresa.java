/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.prjempresa;

/**
 *
 * @author aluno
 */
public class PrjEmpresa {

    public static void main(String[] args) {
        
        Empresa oEmpresa = new Empresa("Vivo", 100);
        Funcionario oFuncionario = new Funcionario("Sabrina", 1700.00, true, oEmpresa);
        System.out.println("Nome do Funcionário: " + oFuncionario.getNome());
        System.out.println("Salário Bruto do Funcionário: R$" + oFuncionario.getSalBruto());
        System.out.println("Salário Líquido do Funcionário: R$" + oFuncionario.getSalario(oFuncionario.getEmpresa().getQtdFunc()));
        System.out.println("Nome da Empresa: " + oFuncionario.getEmpresa().getNome());
        System.out.println("Quantidade de funcionarios na empresa: " + oFuncionario.getEmpresa().getQtdFunc());
    }
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package prjpedido;

/**
 *
 * @author aluno
 */
public class Produto {
    protected int codigo;
    protected String descricao;
    protected double valor_unit;

    public Produto() {
    }

    public Produto(int codigo, String descricao, double valor_unit) {
        this.codigo = codigo;
        this.descricao = descricao;
        this.valor_unit = valor_unit;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public double getValor_unit() {
        return valor_unit;
    }

    public void setValor_unit(double valor_unit) {
        this.valor_unit = valor_unit;
    }
    
    
}

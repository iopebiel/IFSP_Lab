/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package prjpedido;

/**
 *
 * @author aluno
 */
public class Perecivel extends Produto {
    private String data_validade;
    private String cidade_origem;

    public Perecivel() {
    }

    public Perecivel(String data_validade, String cidade_origem, int codigo, String descricao, double valor_unit) {
        super(codigo, descricao, valor_unit);
        this.data_validade = data_validade;
        this.cidade_origem = cidade_origem;
    }


    public String getData_validade() {
        return data_validade;
    }

    public void setData_validade(String data_validade) {
        this.data_validade = data_validade;
    }

    public String getCidade_origem() {
        return cidade_origem;
    }

    public void setCidade_origem(String cidade_origem) {
        this.cidade_origem = cidade_origem;
    }
    
    @Override
    public double getValor_unit() {
        return valor_unit;
    }
    
    
    
    
}

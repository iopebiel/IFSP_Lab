/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package prjpedido;

/**
 *
 * @author aluno
 */
public class Permanente extends Produto {
    private double perc_desvalorizacao;
    private boolean escritorio;

    public Permanente() {
    }

    public Permanente(double perc_desvalorizacao, boolean escritorio, int codigo, String descricao, double valor_unit) {
        super(codigo, descricao, valor_unit);
        this.perc_desvalorizacao = perc_desvalorizacao;
        this.escritorio = escritorio;
    }

    public double getPerc_desvalorizacao() {
        return perc_desvalorizacao;
    }

    public void setPerc_desvalorizacao(double perc_desvalorizacao) {
        this.perc_desvalorizacao = perc_desvalorizacao;
    }

    public boolean isEscritorio() {
        return escritorio;
    }

    public void setEscritorio(boolean escritorio) {
        this.escritorio = escritorio;
    }
    
    @Override
    public double getValor_unit() {
        return valor_unit;
    }
    
}

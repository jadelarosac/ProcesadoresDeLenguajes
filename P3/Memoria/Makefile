FUEN=./Texto_plano
SAL=.

Entrega_1.pdf: Entrega_1.tex clean
	pdflatex Entrega_1.tex
	pdflatex Entrega_1.tex
	@make tidy

tidy:
	rm -rf $(SAL)/*.out $(SAL)/*.log $(SAL)/*.toc  $(SAL)/*.aux

clean: tidy
	rm -f $(SAL)/*.pdf

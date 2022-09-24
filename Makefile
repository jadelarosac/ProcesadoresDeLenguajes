FUEN=./Texto_plano
SAL=.

Entrega_%.pdf: Entrega_%.tex clean
	pdflatex $^
	pdflatex $^
	@make tidy

tidy:
	rm -rf $(SAL)/*.out $(SAL)/*.log $(SAL)/*.toc  $(SAL)/*.aux

clean: tidy
	rm -f $(SAL)/*.pdf

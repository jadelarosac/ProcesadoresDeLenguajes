FUEN=./Texto_plano
SAL=.

Memoria.pdf: Memoria.tex clean
	pdflatex Memoria.tex
	pdflatex Memoria.tex
	@make tidy

tidy:
	rm -rf $(SAL)/*.out $(SAL)/*.log $(SAL)/*.toc  $(SAL)/*.aux

clean: tidy
	rm -f $(SAL)/*.pdf

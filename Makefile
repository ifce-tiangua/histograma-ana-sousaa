saida.out:
	gcc main.c

clean:
	rm a.out

test-inputs: test1 test2 test3 clean

test-alloc: test4 test5 clean

test1: saida.out
	bash ./testes/test1.sh

test2: saida.out
	bash ./testes/test2.sh

test3: saida.out
	bash ./testes/test3.sh

test4: saida.out clean
	bash ./testes/test4.sh

test5: saida.out clean
	bash ./testes/test5.sh
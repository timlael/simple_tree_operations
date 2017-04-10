all: *.c
	gcc -g -Wall -o P0 *.c

clean:
	$(RM) P0 *.inorder *.preorder *.postorder
realclean:
	$(RM) P0 *.inorder *.preorder *.postorder *.datE01

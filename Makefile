default: billboard

billboard: billboard.o termbox.o utf8.o
	gcc -o billboard termbox.o billboard.o utf8.o

billboard.o: billboard.c
	gcc -c billboard.c

termbox.o: termbox/termbox.c termbox/termbox.h termbox/utf8.c termbox/bytebuffer.inl termbox/input.inl termbox/term.inl 
	gcc -c termbox/termbox.c

utf8.o: termbox/utf8.c
	gcc -c termbox/utf8.c

clean:
	$(RM) billboard *.o


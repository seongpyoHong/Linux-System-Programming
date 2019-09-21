#Target : info_tms
TARGET  = info_tms

#INfOLIBDIR ㅇ
INFOLIBDIR = ${INFORMIXDIR}/lib
INFOELIBDIR = ${INFORMIXDIR}/esql
INFOLIBD = ${INFORMIXDIR}/lib/esql
INFOLIBS = -lifsql -lifasf -lifgen -lifos -lifgls -lm -ldl -lcrypt 
           /opt/informix/lib/esql/checkapi.o
 -lifglx -lifxa
# solaris는 라이브러리에 –lnsl –lsocket –laio –lelf 추가

CFLAGS =-O -I$(INFORMIXDIR)/incl/esql -I$(TMAXDIR)
# Solaris 32bit, Compaq, Linux: CFLAGS = -O -I$(INFORMIXDIR)/incl/esql 
                                         –I$(TMAXDIR)
# Solaris 64bit: CFLAGS = -xarch=v9 -O -I$(INFORMIXDIR)/incl/esql –I$(TMAXDIR)
# HP 32bit: CFLAGS = -Ae -O -I$(INFORMIXDIR)/incl/esql –I$(TMAXDIR)
# HP 64bit: CFLAGS = -Ae +DA2.0W +DD64 +DS2.0 -O -I$(INFORMIXDIR)/incl/esql 
                     –I$(TMAXDIR)
# IBM 32bit: CFLAGS = -q32 –brtl -O -I$(INFORMIXDIR)/incl/esql –I$(TMAXDIR
# IBM 64bit: CFLAGS = -q64 –brtl -O -I$(INFORMIXDIR)/incl/esql –I$(TMAXDIR

TMAXLIBDIR = $(TMAXDIR)/lib
TMAXLIBS  = -ltms -linfs
# CC = /opt/SUNWspro/bin/cc : solaris only


$(TARGET): $(APOBJ)
        $(CC) $(CFLAGS) -o $(TARGET) -L$(TMAXLIBDIR) -L$(INFOLIBD) 
        -L$(INFOLIBDIR) -L
$(INFOELIBDIR) $(INFOLIBS) $(TMAXLIBS)
        mv $(TARGET) $(TMAXDIR)/appbin

#
clean:
        -rm -f  *.o core $(TARGET)

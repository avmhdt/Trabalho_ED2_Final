

N <- c(1000, 5000, 10000, 50000, 100000, 500000)

#***********************************************************************************
#************CENARIO 1*************
timeQuickDeputados <- c(0.0048062, 0.030969, 0.07712, 1.04248, 3.57413, 83.2762)
timeQuickInteiros <- c(0.0001356, 0.0007382, 0.0018682, 0.0214904, 0.064765, 1.26934)

compQuickDeputados <- c(11261, 79790, 197640, 2551915, 8899232, 197527310)
compQuickInteiros <- c(11261, 79790, 197640, 2551915, 8899232, 197527310)

copiasQuickDeputados <- c(6652, 52054, 147580, 2289060, 8360755, 194814933)
copiasQuickInteiros <- c(6652, 52054, 147580, 2289060, 8360755, 194814933)


pdf("/home/josecarvalho/Documents/Atividades/Atividades/timeCenario1.pdf")
plot(x = N, y = timeQuickDeputados, pch = 8, col = "red", ylab = "Tempo Médio de CPU (segundos)", log = "y", ylim = c(0.0001, 100))
points(x= N, y = timeQuickInteiros, pch = 12, col = "blue")
legend(x = 200000, y = 1e-2,
       legend = c("Inteiros", "Deputados"),
       col = c("blue", "red"), pch = c(12, 8), lwd = 1)
dev.off()


pdf("/home/josecarvalho/Documents/Atividades/Atividades/compCenario1.pdf")
plot(x = N, y = compQuickDeputados, pch = 8, col = "red", ylab = "Número Médio de Comparações", log = "y")
points(x= N, y = compQuickInteiros, pch = 12, col = "blue")
legend(x = 200000, y = 1e+05,
       legend = c("Inteiros", "Deputados"),
       col = c("blue", "red"), pch = c(12, 8), lwd = 1)
dev.off()


pdf("/home/josecarvalho/Documents/Atividades/Atividades/copiasCenario1.pdf")
plot(x = N, y = copiasQuickDeputados, pch = 8, col = "red", ylab = "Número Médio de Cópias", log = "y")
points(x= N, y = copiasQuickInteiros, pch = 12, col = "blue")
legend(x = 200000, y = 1e+05,
       legend = c("Inteiros", "Deputados"),
       col = c("blue", "red"), pch = c(12, 8), lwd = 1)
dev.off()


TIME1 <- as.matrix(data.frame(rbind(timeQuickInteiros, timeQuickDeputados)))
colnames(TIME1) <- c("1000", "5000", "10000", "50000", "100000", "500000")

pdf("/home/josecarvalho/Documents/Atividades/Atividades/timeBarplotCenario1.pdf")
barplot(TIME1, col=c("blue", "red") , border="white", font.axis=2, beside=T,
        xlab="N", font.lab=2, ylab = "Tempo Médio de CPU (segundos)", log = "y")
legend(x = 1, y = 80, legend=c("Inteiros", "Deputados"), fill = c("blue", "red"))
dev.off()


COMP1 <- as.matrix(data.frame(rbind(compQuickInteiros, compQuickDeputados)))
colnames(COMP1) <- c("1000", "5000", "10000", "50000", "100000", "500000")

pdf("/home/josecarvalho/Documents/Atividades/Atividades/compBarplotCenario1.pdf")
barplot(COMP1, col=c("blue", "red") , border="white", font.axis=2, beside=T,
        xlab="N", font.lab=2, ylab = "Número Médio de Comparações", log = "y")
legend(x = 1, y = 5e08/3, legend=c("Inteiros", "Deputados"), fill = c("blue", "red"))
dev.off()


COPIAS1 <- as.matrix(data.frame(rbind(copiasQuickInteiros, copiasQuickDeputados)))
colnames(COPIAS1) <- c("1000", "5000", "10000", "50000", "100000", "500000")

pdf("/home/josecarvalho/Documents/Atividades/Atividades/copiasBarplotCenario1.pdf")
barplot(COPIAS1, col=c("blue", "red") , border="white", font.axis=2, beside=T,
        xlab="N", font.lab=2, ylab = "Número Médio de Cópias", log = "y")
legend(x = 1, y = 1e09/7, legend=c("Inteiros", "Deputados"), fill = c("blue", "red"))
dev.off()



#***********************************************************************************
#************CENARIO 2*************

timeQuickRecursivo <- c(0.0001398, 0.0007538, 0.0018178, 0.0211194, 0.0674578, 1.24946)
timeQuickMediana3 <- c(0.000416, 0.0020432, 0.004545, 0.040929, 0.110016, 1.95785)
timeQuickMediana5 <- c(0.0005624, 0.0024672, 0.0055122, 0.0428264, 0.114062, 1.98743)
timeQuickInsertion10 <- c(0.0001194, 0.0006316, 0.0016488, 0.0192932, 0.0613296, 1.25393)
timeQuickInsertion100 <- c(0.0001464, 0.0007524, 0.001569, 0.0093214, 0.0418638, 1.22184)

compQuickRecursivo <- c(11261, 78997, 197264, 2547158, 8954647, 198011055)
compQuickMediana3 <- c(30076, 210147, 543410, 7365744, 26121186, 590163260)
compQuickMediana5 <- c(38350, 247611, 614627, 7682177, 26747832, 593044311)
compQuickInsertion10 <- c(11498, 73087, 181764, 2512564, 8917656, 197971795)
compQuickInsertion100 <- c(23405, 120946, 234127, 1306843, 6241590, 193055236)

copiasQuickRecursivo <- c(6652, 53711, 144707, 2264008, 8352839, 195086102)
copiasQuickMediana3 <- c(11402, 74646, 188215, 2493398, 8771844, 196982739)
copiasQuickMediana5 <- c(15689, 94179, 226745, 2669300, 9131119, 198872145)
copiasQuickInsertion10 <- c(6952, 45624, 124460, 2220314, 8306217, 195036682)
copiasQuickInsertion100 <- c(20691, 100355, 185925, 992989, 5576320, 190027220)


pdf("/home/josecarvalho/Documents/Atividades/Atividades/timeCenario2.pdf")
plot(x = N, timeQuickRecursivo, pch = 8, col = "red", ylab = "Tempo de CPU Médio (segundos)", log = "y", ylim = c(0.0001, 2))
points(x = N, y = timeQuickMediana3, pch = 12, col = "blue")
points(x = N, y = timeQuickMediana5, pch = 10, col = "purple")
points(x = N, y = timeQuickInsertion10, pch = 17, col = "green")
points(x = N, y = timeQuickInsertion100, pch = 18, col = "black")
legend(x = 200000, y = 0.01,
       legend = c("Quicksort Recursivo", "Quicksort Mediana (k=3)", "Quicksort Mediana (k=5)", "Quicksort Insertion (m=10",
                  "Quicksort Insertion (m=100)"),
       col = c("red", "blue", "purple", "green", "black"), pch = c(8, 12, 10, 17, 18), lwd = 1)
dev.off()


pdf("/home/josecarvalho/Documents/Atividades/Atividades/compCenario2.pdf")
plot(x = N, compQuickRecursivo, pch = 8, col = "red", ylab = "Número Médio de Comparações", log = "y", ylim = c(1e04, 1e09/2))
points(x = N, y = compQuickMediana3, pch = 12, col = "blue")
points(x = N, y = compQuickMediana5, pch = 10, col = "purple")
points(x = N, y = compQuickInsertion10, pch = 17, col = "green")
points(x = N, y = compQuickInsertion100, pch = 18, col = "black")
legend(x = 200000, y = 1e06,
       legend = c("Quicksort Recursivo", "Quicksort Mediana (k=3)", "Quicksort Mediana (k=5)", "Quicksort Insertion (m=10",
                  "Quicksort Insertion (m=100)"),
       col = c("red", "blue", "purple", "green", "black"), pch = c(8, 12, 10, 17, 18), lwd = 1)
dev.off()


pdf("/home/josecarvalho/Documents/Atividades/Atividades/copiasCenario2.pdf")
plot(x = N, copiasQuickRecursivo, pch = 8, col = "red", ylab = "Número Médio de Cópias", log = "y", ylim = c(1e04/2, 1e09/4))
points(x = N, y = copiasQuickMediana3, pch = 12, col = "blue")
points(x = N, y = copiasQuickMediana5, pch = 10, col = "purple")
points(x = N, y = copiasQuickInsertion10, pch = 17, col = "green")
points(x = N, y = copiasQuickInsertion100, pch = 18, col = "black")
legend(x = 200000, y = 1e06,
       legend = c("Quicksort Recursivo", "Quicksort Mediana (k=3)", "Quicksort Mediana (k=5)", "Quicksort Insertion (m=10)",
                  "Quicksort Insertion (m=100)"),
       col = c("red", "blue", "purple", "green", "black"), pch = c(8, 12, 10, 17, 18), lwd = 1)
dev.off()


TIME2 <- as.matrix(data.frame(rbind(timeQuickRecursivo, timeQuickMediana3,
                                    timeQuickMediana5, timeQuickInsertion10, timeQuickInsertion100)))
colnames(TIME2) <- c("1000", "5000", "10000", "50000", "100000", "500000")

pdf("/home/josecarvalho/Documents/Atividades/Atividades/timeBarplotCenario2.pdf")
barplot(TIME2, col=c("red", "blue", "purple", "green", "black") , border="white", font.axis=2, beside=T,
        xlab="N", font.lab=2, ylab = "Tempo Médio de CPU (segundos)", log = "y")
legend(x = 1, y = 5/3, legend=c("Quicksort Recursivo", "Quicksort Mediana (k=3)", "Quicksort Mediana (k=5)",
                               "Quicksort Insertion (m=10)", "Quicksort Insertion (m=100)"),
       fill = c("red", "blue", "purple", "green", "black"))
dev.off()


COMP2 <- as.matrix(data.frame(rbind(compQuickRecursivo, compQuickMediana3,
                                    compQuickMediana5, compQuickInsertion10, compQuickInsertion100)))
colnames(COMP2) <- c("1000", "5000", "10000", "50000", "100000", "500000")

pdf("/home/josecarvalho/Documents/Atividades/Atividades/compBarplotCenario2.pdf")
barplot(COMP2, col=c("red", "blue", "purple", "green", "black") , border="white", font.axis=2, beside=T,
        xlab="N", font.lab=2, ylab = "Número Médio de Comparações", log = "y")
legend(x = 1, y = 5e8, legend=c("Quicksort Recursivo", "Quicksort Mediana (k=3)", "Quicksort Mediana (k=5)",
                                "Quicksort Insertion (m=10)", "Quicksort Insertion (m=100)"),
       fill = c("red", "blue", "purple", "green", "black"))
dev.off()


COPIAS2 <- as.matrix(data.frame(rbind(copiasQuickRecursivo, copiasQuickMediana3,
                                      copiasQuickMediana5, copiasQuickInsertion10, copiasQuickInsertion100)))
colnames(COPIAS2) <- c("1000", "5000", "10000", "50000", "100000", "500000")

pdf("/home/josecarvalho/Documents/Atividades/Atividades/copiasBarplotCenario2.pdf")
barplot(COPIAS2, col=c("red", "blue", "purple", "green", "black") , border="white", font.axis=2, beside=T,
        xlab="N", font.lab=2, ylab = "Número Médio de Cópias", log = "y")
legend(x = 1, y = 1e9/7, legend=c("Quicksort Recursivo", "Quicksort Mediana (k=3)", "Quicksort Mediana (k=5)",
                                "Quicksort Insertion (m=10)", "Quicksort Insertion (m=100)"),
       fill = c("red", "blue", "purple", "green", "black"))
dev.off()


#***********************************************************************************
#************CENARIO 3*************

timeQuickInsertion100 <- c(0.0002782, 0.0009128, 0.0019464, 0.010515, 0.0503384, 1.53142)
timeInsertionSort <- c(0.001759, 0.0328126, 0.114847, 2.7394, 10.8174, 282.069)
timeMergeSort <- c(0.000397, 0.0016342, 0.0040398, 0.016448, 0.0327732, 0.175349)
timeHeapSort <- c(0.0064756, 0.143827, 0.484715, 9.60385, 37.3693, 805.575)
timeCountingSort <- c(5.18e-05, 0.000144, 0.000227, 0.001512, 0.0032012, 0.0106524)

compQuickInsertion100 <- c(23405, 121446, 232145, 1305734, 6195081, 192565549)
compInsertionSort <- c(249573, 6260792, 24969571, 623790327, 776874100, 561752736)
compMergeSort <- c(8707, 55224, 120445, 718213, 1536325, 8837163)
compHeapSort <- c(499500, 12497500, 49995000, 390981540, 704982704, 445698416)
compCountingSort <- c(0, 0, 0, 0, 0, 0)

copiasQuickInsertion100 <- c(20691, 98277, 186304, 1011819, 5593326, 189750004)
copiasInsertionSort <- c(249573, 6260792, 24969571, 623790327, 776874100, 561752736)
copiasMergeSort <- c(9976, 61808, 133616, 784464, 1668928, 9475712)
copiasHeapSort <- c(160175, 2636603, 7591515, 70050742, 171034064, 325645141)
copiasCountingSort <- c(2000, 10000, 20000, 100000, 200000, 1000000)


pdf("/home/josecarvalho/Documents/Atividades/Atividades/timeCenario3.pdf")
plot(x = N, timeQuickInsertion100, pch = 8, col = "red", ylab = "Tempo de CPU Médio (segundos)", log = "y", ylim = c(1e-5, 600))
points(x = N, y = timeInsertionSort, pch = 12, col = "blue")
points(x = N, y = timeMergeSort, pch = 10, col = "purple")
points(x = N, y = timeHeapSort, pch = 17, col = "green")
points(x = N, y = timeCountingSort, pch = 18, col = "black")
legend(x = 180000, y = 0.01,
       legend = c("Quicksort Insertion (m=100)", "Insertion Sort", "Mergesort", "Heapsort",
                  "Counting Sort"),
       col = c("red", "blue", "purple", "green", "black"), pch = c(8, 12, 10, 17, 18), lwd = 1)
dev.off()


pdf("/home/josecarvalho/Documents/Atividades/Atividades/compCenario3.pdf")
plot(x = N, compQuickInsertion100, pch = 8, col = "red", ylab = "Número Médio de Comparações", log = "y", ylim = c(5e3, 5e9/2))
points(x = N, y = compInsertionSort, pch = 12, col = "blue")
points(x = N, y = compMergeSort, pch = 10, col = "purple")
points(x = N, y = compHeapSort, pch = 17, col = "green")
points(x = N, y = compCountingSort, pch = 18, col = "black")
legend(x = 200000, y = 1e06,
       legend = c("Quicksort Insertion (m=100)", "Insertion Sort", "Mergesort", "Heapsort"),
       col = c("red", "blue", "purple", "green"), pch = c(8, 12, 10, 17), lwd = 1)
dev.off()


pdf("/home/josecarvalho/Documents/Atividades/Atividades/copiasCenario3.pdf")
plot(x = N, copiasQuickInsertion100, pch = 8, col = "red", ylab = "Número Médio de Cópias", log = "y", ylim = c(5e3/3, 5e9/2))
points(x = N, y = copiasInsertionSort, pch = 12, col = "blue")
points(x = N, y = copiasMergeSort, pch = 10, col = "purple")
points(x = N, y = copiasHeapSort, pch = 17, col = "green")
points(x = N, y = copiasCountingSort, pch = 18, col = "black")
legend(x = 180000, y = 1e6/2,
       legend = c("Quicksort Insertion (m=100)", "Insertion Sort", "Mergesort", "Heapsort",
                  "Counting Sort"),
       col = c("red", "blue", "purple", "green", "black"), pch = c(8, 12, 10, 17, 18), lwd = 1)
dev.off()


TIME3 <- as.matrix(data.frame(rbind(timeQuickInsertion100, timeInsertionSort,
                                    timeMergeSort, timeHeapSort, timeCountingSort)))
colnames(TIME3) <- c("1000", "5000", "10000", "50000", "100000", "500000")

pdf("/home/josecarvalho/Documents/Atividades/Atividades/timeBarplotCenario3.pdf")
barplot(TIME3, col=c("red", "blue", "purple", "green", "black") , border="white", font.axis=2, beside=T,
        xlab="N", font.lab=2, ylab = "Tempo Médio de CPU (segundos)", log = "y")
legend(x = 1, y = 800, legend=c("Quicksort Insertion (m=100)", "Insertion Sort", "Mergesort",
                                "Heapsort", "Counting Sort"),
       fill = c("red", "blue", "purple", "green", "black"), bty = "n")
dev.off()


COMP3 <- as.matrix(data.frame(rbind(compQuickInsertion100, compInsertionSort,
                                    compMergeSort, compHeapSort)))
colnames(COMP3) <- c("1000", "5000", "10000", "50000", "100000", "500000")

pdf("/home/josecarvalho/Documents/Atividades/Atividades/compBarplotCenario3.pdf")
barplot(COMP3, col=c("red", "blue", "purple", "green") , border="white", font.axis=2, beside=T,
        xlab="N", font.lab=2, ylab = "Número Médio de Comparações", log = "y")
legend(x = 0, y = 1e9, legend=c("Quicksort Insertion (m=100)", "Insertion Sort", "Mergesort",
                                "Heapsort"),
       fill = c("red", "blue", "purple", "green"), bty = "n")
dev.off()


COPIAS3 <- as.matrix(data.frame(rbind(copiasQuickInsertion100, copiasInsertionSort,
                                    copiasMergeSort, copiasHeapSort, copiasCountingSort)))
colnames(COPIAS3) <- c("1000", "5000", "10000", "50000", "100000", "500000")

pdf("/home/josecarvalho/Documents/Atividades/Atividades/copiasBarplotCenario3.pdf")
barplot(COPIAS3, col=c("red", "blue", "purple", "green", "black") , border="white", font.axis=2, beside=T,
        xlab="N", font.lab=2, ylab = "Número Médio de Cópias", log = "y")
legend(x = 0, y = 1e9, legend=c("Quicksort Insertion (m=100)", "Insertion Sort", "Mergesort",
                                "Heapsort", "Counting Sort"),
       fill = c("red", "blue", "purple", "green", "black"), bty = "n")
dev.off()


#***********************************************************************************
#************CENARIO 4*************

compSondLinear <- c(688844656, 692701056, 791901056, 331951596, 19070086, 492850963)
compEncadCoalescido <- c(692691056, 791881056, 331851596, 18870086, 491850963, 273176166)

memSondLinear <- c(37860147, 42198630, 5935923, 87696998, 35373056, 585664454)
memEncadCoalescido <- c(40173568, 416153, 22586982, 781705216, 12388761, 249933824)

pdf("/home/josecarvalho/Documents/Atividades/Atividades/memCenario4.pdf")
plot(x = N, y = memEncadCoalescido, pch = 8, col = "red", ylab = "Memória Usada (Média)", log = "y")#, ylim = c(0.0001, 100))
points(x= N, y = memSondLinear, pch = 12, col = "blue")
legend(x = 2e5, y = 5e6,
       legend = c("Encadeamento Coalescido", "Sondagem Linear"),
       col = c("red", "blue"), pch = c(8, 12), lwd = 1)
dev.off()

pdf("/home/josecarvalho/Documents/Atividades/Atividades/compCenario4.pdf")
plot(x = N, y = compEncadCoalescido, pch = 8, col = "red", ylab = "Número Médio de Comparações", log = "y")
points(x= N, y = compSondLinear, pch = 12, col = "blue")
legend(x = 2e5, y = 5e7,
       legend = c("Encadeamento Coalescido", "Sondagem Linear"),
       col = c("red", "blue"), pch = c(8, 12), lwd = 1)
dev.off()

MEM4 <- as.matrix(data.frame(rbind(memEncadCoalescido, memSondLinear)))
colnames(MEM4) <- c("1000", "5000", "10000", "50000", "100000", "500000")

pdf("/home/josecarvalho/Documents/Atividades/Atividades/memBarplotCenario4.pdf")
barplot(MEM4, col=c("red", "blue") , border="white", font.axis=2, beside=T,
        xlab="N", font.lab=2, ylab = "Memória Utilizada em Média (kBytes)", log = "y")
legend(x = 0, y = 6e8, legend=c("Encadeamento Coalescido", "Sondagem Linear"), fill = c("red", "blue"), bty = "n")
dev.off()


COMP4 <- as.matrix(data.frame(rbind(compEncadCoalescido, compSondLinear)))
colnames(COMP4) <- c("1000", "5000", "10000", "50000", "100000", "500000")

pdf("/home/josecarvalho/Documents/Atividades/Atividades/compBarplotCenario4.pdf")
barplot(COMP4, col=c("red", "blue") , border="white", font.axis=2, beside=T,
        xlab="N", font.lab=2, ylab = "Número Médio de Comparações", log = "y")
legend(x = 8, y = 1e09/7, legend=c("Encadeamento Coalescido", "Sondagem Linear"), fill = c("red", "blue"), bg = "white")
dev.off()

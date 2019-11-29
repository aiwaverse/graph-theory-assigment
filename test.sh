rm m_respostas.txt
touch m_respostas.txt
for i in {1..10}
do
	f=$( printf '%02d' $i )
	f="teste${f}.txt"
	./graph < $f >> m_respostas.txt
done
r= diff respostas.txt m_respostas.txt
echo $r
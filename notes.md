* PUSH SWAP 
	Push swap é progetto su un ordinamento in ordine crescente di X numeri nel minor numero di mosse possibili. Il goal é trovare ed implementare l'algoritmo piu efficiente. Per ordinare questi numeri si hanno a disposizione due pile, la pila A e la pila B. I entrano direttamente nella pila A ed é questa che deve essere ordinata, la pila B verrá utilizzata come pila ausiliaria per compiere le operazione. Questi numeri si passsano da terminale, non possono essere doppi, possono essere negativi o positivi e devono essere ordinati con mosse specifiche.
      - SA (swap A) Swappa i primi due elementi nella pila A; es:[3,4,6,9,1] --> SA --> [4,3,6,9,1] (NB. 3 e 4 sono i primi due numeri inseriti).
    	- SB (swap B).
    	- SS (SA and SB at the same time)
    	- PA (push A) Pusha un numero in una pila; es:PILA B[1,2,34,5,6] --> PA -->[1] (NB. é stato preso il primo numero della pila B ed é stato pushato nella pila A)
  		- PB (push B).
  		- RA (rotate A) Prende il primo elemento di una pila e lo mette per ultimo; es:[3,2,5,7,1] --> RA --> [2,5,7,1,3]
  		- RB (rotate B).
  		- RR (RA and RB at the same time).
  		- RRA (reverse rotate A) É l'operazione inversa di rotate, quindi prende l'ultimo elemento di una pila e lo mette come primo; es:[2,5,7,1,3] --> RRA --> [3,2,5,7,1] 
  		- RRB (reverse rotate B).
  		- RRR (rra and rrb at the same time).
	Quando i numeri vengono acquisiti da terminale all' inizio non sono contate come mosse.
	Il numero massimo di mosse che si possono utilizzare per ordinare é 11 volte il numero di numeri in input.
	Il programma verrá testato con il checker che trovo nel sub.
	Per la scelta dell'algoritmo devo considerare il numero di elementi in input.
	QUICKSORT e MEGASORT sono due algoritmi efficienti per un numero elevato di elementi. 
	BUBBLE SORT e INSERTION SORT sono algoritmi efficienti per un numero basso di elementi.

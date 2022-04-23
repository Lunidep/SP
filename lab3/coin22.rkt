;coin22.cpp

; вариант - номер в писке группы
(define VARIANT 17)
;количество имеющихся номинмалов монет
(define COINS 4)

(define(largest coins-set)
  (cond((= coins-set 1) 2)
       ((= coins-set 2) 5)
       ((= coins-set 3) 15)
       ((= coins-set 4) 25)
       (else 0))
)

(define (count-change amount)
  (display "______\n amount: ");
  (display amount);
  (newline);
  (display "COINS: ");
  (display COINS);
  (newline);
  (if (or (<= amount 0) (< COINS 1) (= (largest COINS) 0))
          (let()(display "Improper parameter value!\ncount-change= ")
            -1) ;let #1
          (let() (display "List of coin denominations: ")
            (denomination-list COINS)
            (display "count-change= ")
            (cc amount COINS)
            );let #2
  );if
)

(define (Shaeffer? x? y?)
  (not(and x? y?))
)

(define (cc amount coins-set)
  (cond((= amount 0) 1)
       ((Shaeffer? (>= amount 1) (> coins-set 0)) 0)
       (else (+ (cc amount (- coins-set 1))
                    (cc (- amount (largest coins-set)) coins-set)))
   )
)


(define (denomination-list coins-set)
  (if (= coins-set 0) (let() (newline) 0)
      (let() (display(largest coins-set))
        (display " ")
        (denomination-list (- coins-set 1))
       );let
  );if
)

(display "Variant ") 
(display VARIANT);
(newline)
(display (count-change 100) )
(newline)
(set! COINS 13)
(display (count-change 100) )
(newline)
(display "(c) Ilya Popov 2022\n")


;coin22.cpp

; вариант - номер в писке группы
(define VARIANT 17)
;количество имеющихся номинмалов монет
(define COINS 4)

(define(largest coins-set)
  (cond((= coins-set 1)
      2)
  (else 
      (cond((= coins-set 2)
            5)
      (else 
            (cond((= coins-set 3)
                  15)
            (else 
                  (cond((= coins-set 4)
                        25)
                  (else 
                        0))
            )
            )
       )
       )
   )
   )
)


(define (count-change amount)
  (display "______\n amount: ");
  (display amount);
  (newline);
  (display "COINS: ");
  (display COINS);
  (newline);
  (cond (
         (not(and (not(not(< 0 amount))) (not(< COINS 1)) (not(= (largest COINS) 0)) ))
          (let()(display "Improper parameter value!\ncount-change= ")
            -1) ;let #1
          )
        (else 
          (let() (display "List of coin denominations: ")
            (denomination-list COINS)
            (display "count-change= ")
            (cc amount COINS)
            );let #2
         )
  );cond
)

(define (Shaeffer? x? y?)
  (not(and x? y?))
)

(define (cc amount coins-set)
  (cond((= amount 0)
        1)
  (else 
        (cond((Shaeffer? ( not(< amount 1)) (< 0 coins-set))
             0)
        (else 
              (+ (cc amount (- coins-set 1))
                  (cc (- amount (largest coins-set)) coins-set))
         )
         )
  )
  )
)



(define (denomination-list coins-set)
  (cond ((= coins-set 0)
           (let() (newline) 0)
         )
   (else 
         (let() (display(largest coins-set))
            (display " ")
            (denomination-list (- coins-set 1))
          )
   )
   )
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





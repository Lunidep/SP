;half22 for 206
(define (root a b)
 (define temp 0)
 (set! temp (half-interval a b (f a)(f b)))
  (display"Total number of iteranions=")
  (display total-iterations)(newline)
 (display"[")
 (display a)
 (display" , ")
 (display b)
 (display"]")
      temp 
)
(define (half-interval a b fa fb)
 (define root 0)
 (set! total-iterations 0)
   (set! root(cond((and(< fa 0)(< 0 fb))
                   (try a b))
              (else 
                   (cond((and(< 0 fa)(< fb 0))
                          (try b a))
                   (else 
                          (+ b 1)))
                    )
              )
    )
  (newline)
  root
)


(define(try neg-point pos-point)
 (define midpoint 0)
 (define test-value 0)
     (set! midpoint (average neg-point pos-point))
     (display "+")
     (set! total-iterations (+ total-iterations 1))
     (cond ((close-enough? neg-point pos-point)
            midpoint)
      (else  (let() (set! test-value (f midpoint))
               (cond((< 0 test-value)
                     (try neg-point midpoint))
                (else 
                      (cond((< test-value 0)
                           (try midpoint pos-point))
                        (else 
                            midpoint)
                        )
                        )
                )
                )
        )
        )
)

(define (close-enough? x y)
  (<(abs (- x y))tolerance))


(define (average x y)(*(+ x y)(/ (* 2))))


(define tolerance +.001e0)
(define total-iterations 0)

(define(f z)
  (+(* (exp(- z)) (sin(+ z pi)))
    (cos z)
    120) 
)

 (display"Variant 206-17\n")
 (root -6 -.549e1)
 (display"(c) Ilya Popov 2022\n")
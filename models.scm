;;; Models of some metafunctions in Scheme

;; 3-0
(define fill-vec
  (lambda (n v)
    (if (= n 0)
        v
        (fill-vec (/ (- n (% n 10) 10))
                  (push (% n 10) v)))))

; equality ops? true/false vals?
(define illegal-numeral
  (lambda (n)
    (if (= n 0)
        nil
        (let ((digit (% n 10)))
          (if (or (not (equal digit 0)) (not (equal digit 1)))
              t
              (illegal-numeral (/ (- n (% n 10) 10))))))))

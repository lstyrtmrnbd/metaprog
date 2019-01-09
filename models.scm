;;; Models of some metafunctions in Scheme

;; 3-0
(define fill-vec
  (lambda (n v)
    (cond ((= n 0) v)
	  (else
	   (fill-vec (/ (- n (% n 10) 10))
		     (push (% n 10) v))))))

(define illegal-numeral
  (lambda (n)
    (cond ((= n 0) #f)
	  (else
	   (let ((digit (% n 10)))
	     (cond ((or (not (equal digit 0)) (not (equal digit 1))) #t)
		   (else (illegal-numeral (/ (- n (% n 10) 10))))))))))

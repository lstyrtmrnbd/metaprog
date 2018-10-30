;;; Models of some metafunctions in scheme

;; 3-0
(define fill_vec
  (lambda (n v)
    (if (= n 0)
        v
        (fill_vec (/ (- n (% n 10) 10))
                  (push_back (% n 10) v)))))

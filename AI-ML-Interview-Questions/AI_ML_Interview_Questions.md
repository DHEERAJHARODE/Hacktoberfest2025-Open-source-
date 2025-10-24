# AI / ML Interview Questions (Starter)

Author: Starter — add your name when contributing
Date: 2025-10-24

This file contains a compact set of starter interview questions and short answers to help contributors get started. Add more Q&A files under this folder or split long sections into numbered files.

---

### Q1 — What is overfitting?

**Answer:** Overfitting happens when a model learns the training data (including noise) too well and performs poorly on unseen data.

**Explanation:** Common fixes include collecting more data, using regularization (L1/L2), early stopping, dropout, or choosing a simpler model.

**Reference:** https://en.wikipedia.org/wiki/Overfitting

---

### Q2 — What is the bias–variance tradeoff?

**Answer:** Bias is error from erroneous assumptions (underfitting); variance is error from sensitivity to small fluctuations in the training set (overfitting). The tradeoff balances model complexity to minimize total error.

**Explanation:** Low-bias/high-variance models (very complex) overfit; high-bias/low-variance models (too simple) underfit.

---

### Q3 — Supervised vs. Unsupervised learning — what's the difference?

**Answer:** Supervised learning uses labeled data to learn a mapping from inputs to outputs. Unsupervised learning finds structure in unlabeled data (e.g., clustering, dimensionality reduction).

**Explanation:** Examples: classification/regression = supervised; K-means, PCA = unsupervised.

---

### Q4 — What is gradient descent?

**Answer:** Gradient descent is an optimization algorithm that iteratively updates model parameters in the negative direction of the gradient of the loss to find a local minimum.

**Explanation:** Variants include batch, stochastic, and mini-batch gradient descent. Learning rate selection is critical.

---

### Q5 — What is regularization and why use it?

**Answer:** Regularization adds a penalty to the loss (e.g., L1 or L2) to discourage complex models and reduce overfitting.

**Explanation:** L1 (Lasso) encourages sparsity; L2 (Ridge) penalizes large weights but keeps them small.

---

### Q6 — What is cross-validation? Why use it?

**Answer:** Cross-validation (e.g., k-fold) splits data into multiple train/test folds to estimate model generalization and tune hyperparameters without using the test set.

**Explanation:** Commonly used to reduce variance of the performance estimate and select hyperparameters.

---

### Q7 — Precision vs. Recall — when do you optimize which?

**Answer:** Precision measures correctness among positive predictions; recall measures coverage of actual positives. Optimize precision when false positives are costly; optimize recall when false negatives are costly.

**Explanation:** F1-score balances them; choose based on application (spam detection vs. disease screening).

---

### Q8 — What is PCA (Principal Component Analysis)?

**Answer:** PCA is a linear dimensionality reduction technique that projects data onto orthogonal directions (principal components) of maximum variance.

**Explanation:** Use PCA to reduce dimensionality for visualization or as a preprocessing step; it is unsupervised and linear.

---

### Q9 — What is the difference between classification and regression?

**Answer:** Classification predicts discrete class labels; regression predicts continuous numeric values.

**Explanation:** Examples: logistic regression (classification), linear regression (regression).

---

### Q10 — What is an embedding and why are embeddings useful?

**Answer:** An embedding maps discrete objects (words, categories) to continuous vectors that capture semantic relationships and can be used as inputs to ML models.

**Explanation:** Pretrained embeddings (word2vec, GloVe) speed up learning and capture similarity between tokens.

---

If you add more questions, follow the same short format (Question → Answer → Explanation → Reference). When creating a PR, mention how many Q&A you added and link to the issue template or issue file if applicable.

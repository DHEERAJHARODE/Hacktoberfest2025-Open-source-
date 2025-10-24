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

---

### Q11 — What is a confusion matrix?

**Answer:** A confusion matrix summarizes classification results with counts of true positives, true negatives, false positives, and false negatives.

**Explanation:** It helps compute metrics like accuracy, precision, recall, and F1-score and is useful for multiclass evaluation.

---

### Q12 — What is ROC AUC?

**Answer:** ROC AUC is the Area Under the Receiver Operating Characteristic curve; it measures a classifier's ability to separate classes across thresholds.

**Explanation:** AUC ranges from 0 to 1; 0.5 is random guessing, higher is better and it's threshold-independent.

---

### Q13 — What causes vanishing and exploding gradients?

**Answer:** Vanishing/exploding gradients occur in deep networks when repeated multiplications during backpropagation make gradients extremely small or large, preventing learning or causing instability.

**Explanation:** Remedies include proper weight initialization, batch normalization, residual connections, and using ReLU-like activations.

---

### Q14 — What is batch normalization and why use it?

**Answer:** Batch normalization rescales and recenters layer inputs using batch statistics to stabilize and accelerate training.

**Explanation:** It allows higher learning rates, reduces sensitivity to initialization, and can act as mild regularization.

---

### Q15 — What is dropout?

**Answer:** Dropout randomly zeroes neuron activations during training to prevent co-adaptation and reduce overfitting.

**Explanation:** At inference, activations are scaled appropriately; dropout is often used in fully connected layers.

---

### Q16 — Difference between CNN and RNN?

**Answer:** CNNs use convolutional filters to capture spatial/local patterns (images); RNNs process sequential data, maintaining state across time steps.

**Explanation:** Use CNNs for images/structured grids and RNNs (or transformers) for sequences like text or time series.

---

### Q17 — What is attention (in transformers)?

**Answer:** Attention computes weighted combinations of values based on similarity between queries and keys, allowing models to focus on relevant parts of the input.

**Explanation:** Self-attention lets each token attend to others; transformers scale this with multi-head attention for richer representations.

---

### Q18 — What is transfer learning?

**Answer:** Transfer learning reuses a pretrained model or its features on a new task, often fine-tuning on smaller datasets to speed up training and improve performance.

**Explanation:** Common in vision (ImageNet-pretrained backbones) and NLP (BERT/Transformer fine-tuning).

---

### Q19 — What is data augmentation and why use it?

**Answer:** Data augmentation applies label-preserving transformations (rotations, flips, noise) to increase dataset size and variety.

**Explanation:** It reduces overfitting and improves model robustness, especially when original data is limited.

---

### Q20 — What is ensembling and why does it help?

**Answer:** Ensembling combines multiple models' predictions (e.g., bagging, boosting, stacking) to improve accuracy and robustness.

**Explanation:** Ensembles reduce variance and can correct individual model biases; Random Forests and Gradient Boosting are common examples.

---

### Q21 — What is gradient clipping?

**Answer:** Gradient clipping caps gradients to a fixed threshold to prevent exploding gradients during optimization.

**Explanation:** Commonly used in RNN training where long sequences can cause large gradients.

---

### Q22 — What are activation functions and why choose ReLU?

**Answer:** Activation functions introduce non-linearity. ReLU is simple (max(0,x)), sparsifies activations, and reduces vanishing-gradient issues compared to sigmoid/tanh.

**Explanation:** Variants like Leaky ReLU and GELU address ReLU's dying-neuron problem.

---

### Q23 — When to use cross-entropy vs MSE loss?

**Answer:** Use cross-entropy for classification with probabilities (softmax/sigmoid) and MSE (mean squared error) for regression tasks predicting continuous values.

**Explanation:** Cross-entropy aligns with maximum likelihood for categorical outcomes and handles class probabilities better.

---

### Q24 — What is learning rate scheduling?

**Answer:** Learning rate scheduling adjusts the optimizer's learning rate during training (step decay, cosine annealing, warmup) to improve convergence.

**Explanation:** Warmup + decay often stabilizes large models and improves final accuracy.

---

### Q25 — What is early stopping?

**Answer:** Early stopping halts training when validation performance stops improving to avoid overfitting.

**Explanation:** Use a patience parameter to avoid stopping on temporary fluctuations.

---

### Q26 — What is transfer vs fine-tuning?

**Answer:** Transfer typically uses pretrained features as fixed inputs (feature extraction), while fine-tuning updates pretrained model weights on the new task.

**Explanation:** Fine-tuning often yields better performance if you have enough labeled data; otherwise use feature extraction.

---

### Q27 — What is a learning curve?

**Answer:** A learning curve plots model performance (train/validation) versus training size or epochs, showing trends like overfitting or underfitting.

**Explanation:** Use it to diagnose whether more data or model complexity is needed.

---

### Q28 — What is Kullback–Leibler (KL) divergence?

**Answer:** KL divergence measures how one probability distribution diverges from a reference distribution; used in variational inference and as a regularizer.

**Explanation:** KL is asymmetric and non-negative; small KL means distributions are similar.

---

### Q29 — Difference between MAP and MLE?

**Answer:** MLE maximizes the likelihood of observed data w.r.t. parameters; MAP (maximum a posteriori) adds a prior and maximizes the posterior.

**Explanation:** MAP is MLE with regularization derived from the prior; useful when prior knowledge exists.

---

### Q30 — What is model calibration?

**Answer:** Calibration measures whether predicted probabilities match observed frequencies (e.g., among predictions with 0.8 confidence, ~80% are correct).

**Explanation:** Techniques like temperature scaling and isotonic regression can improve calibration for probabilistic models.

---

When you push this change, the open PR will update automatically. Good practice: mention in the PR description that you added 20 new Q&A and list any sources you relied on.

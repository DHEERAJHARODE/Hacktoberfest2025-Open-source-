# AI / ML Interview Questions (Hacktoberfest 2025)

This document contains a curated list of AI and Machine Learning interview questions grouped by topic. It's intended for contributors preparing interview materials or adding content for Hacktoberfest 2025.

If you'd like to be assigned this issue for Hacktoberfest2025, comment on the issue with your GitHub handle (for example: `assign @your-github-username`) or ask a maintainer to assign you.

---

## Quick usage notes

- File purpose: collect well-organized AI/ML interview questions (with quick hints). Contributors may expand answers, add code examples, or convert sections into quiz form.
- Contribution suggestions: add full answers, sample coding tasks, links to references, and tags (easy/medium/hard).

---

## 1) Fundamentals

1. What is the difference between supervised, unsupervised, and reinforcement learning?
   - Hint: labels, clustering vs. prediction, agent/environment/reward.
2. What is bias and variance? How do they impact model performance?
   - Hint: underfitting vs overfitting; training vs test error; tradeoff.
3. Explain the difference between classification and regression.
   - Hint: categorical vs continuous outputs; loss functions differ (cross-entropy vs MSE).
4. What is overfitting? Name three ways to reduce it.
   - Hint: regularization (L1/L2), dropout, early stopping, more data, cross-validation.
5. What is cross-validation and why use it?
   - Hint: k-fold, reliable estimate of generalization, hyperparameter tuning.

## 2) Probability & Statistics

6. What is Bayes' theorem and provide an application in ML.
   - Hint: posterior ∝ likelihood × prior; Naive Bayes classifier.
7. Explain p-value and confidence interval in the context of experiments.
   - Hint: hypothesis testing, type I/II errors, significance.
8. What is the central limit theorem and why is it useful?
   - Hint: sampling distributions, normality for large n.

## 3) Linear Models & Optimization

9. Explain linear regression and ordinary least squares.
   - Hint: minimize sum of squared errors; closed form vs gradient descent.
10. What is logistic regression and how is it trained?
   - Hint: binary classification, sigmoid + cross-entropy, gradient-based optimization.
11. What are L1 and L2 regularization? Compare them.
   - Hint: L1 -> sparsity (feature selection), L2 -> weight shrinkage.
12. Describe gradient descent variants: batch, stochastic, mini-batch.
   - Hint: update frequency vs noise, speed and convergence.
13. Explain learning rate scheduling and its importance.
   - Hint: constant vs decay vs warm restarts; affects convergence and stability.

## 4) Decision Trees, Ensembles

14. How does a decision tree split nodes? What criteria are used?
   - Hint: Gini impurity, information gain (entropy), variance reduction for regression.
15. What is random forest and why does it work well?
   - Hint: bagging + feature sub-sampling; variance reduction and robustness.
16. Explain boosting (e.g., AdaBoost, Gradient Boosting).
   - Hint: sequential learners, focus on mistakes, weighted training.
17. When would you prefer GBM (XGBoost/LightGBM/CatBoost) over neural networks?
   - Hint: tabular data, small/medium dataset, interpretability and less tuning.

## 5) Neural Networks & Deep Learning

18. Describe a basic neural network (MLP) architecture.
   - Hint: layers, activations, forward/backpropagation.
19. What is backpropagation in neural networks?
   - Hint: chain rule to compute gradients, weight updates via optimizer.
20. Explain ReLU, sigmoid, and tanh activations and when to use them.
   - Hint: vanishing gradients, nonlinearity, ReLU sparsity.
21. What are batch normalization and layer normalization?
   - Hint: stabilize/accelerate training by normalizing activations.
22. Explain dropout and its role during training.
   - Hint: prevents co-adaptation; acts like bagging.
23. What is vanishing/exploding gradient and solutions?
   - Hint: careful init, normalization, residual connections, LSTM/GRU.

## 6) Convolutional Neural Networks (CNNs)

24. What is the convolution operation and why is it useful for images?
   - Hint: local receptive fields, parameter sharing, translation invariance.
25. Explain pooling layers and why we use them.
   - Hint: downsampling, reduce computation, build invariance.
26. Describe architectures like AlexNet, VGG, ResNet and the motivation for residuals.
   - Hint: deeper networks require skip connections (ResNet) to ease training.

## 7) Recurrent Networks, Transformers, and Sequence Models

27. What problems do RNNs solve? What are their limitations?
   - Hint: sequential data, long-term dependencies -> LSTM/GRU.
28. What is an LSTM cell broadly (gates idea)?
   - Hint: forget/input/output gates to manage memory.
29. How do Transformers differ from RNNs? What is self-attention?
   - Hint: parallelizable, attention weights compute importance across tokens.
30. Describe positional encoding in Transformers.
   - Hint: inject token position information into inputs.

## 8) Natural Language Processing (NLP)

31. What is word embedding? Name popular techniques.
   - Hint: Word2Vec, GloVe, FastText, contextual (BERT, GPT).
32. What is BERT and how is it trained differently from GPT?
   - Hint: bidirectional masked LM vs autoregressive LM.
33. Explain tokenization and why subword tokenizers (BPE/WordPiece) are used.
   - Hint: balance vocabulary size and handling OOV words.

## 9) Computer Vision

34. What is transfer learning and when to use it?
   - Hint: use pretrained CNNs, fine-tune for smaller datasets.
35. Describe common image augmentation techniques.
   - Hint: flips, rotations, color jitter, cropping, normalization.

## 10) Model Evaluation & Metrics

36. Which metrics are appropriate for imbalanced classification?
   - Hint: precision/recall, F1, AUC-ROC, PR curves, balanced accuracy.
37. How do you evaluate a regression model?
   - Hint: MSE, RMSE, MAE, R^2.
38. Explain confusion matrix and derived metrics.
   - Hint: TP/FP/TN/FN -> precision, recall, specificity.

## 11) Production & MLOps

39. What considerations are important when deploying ML models?
   - Hint: latency, throughput, model size, monitoring, data drift, retraining.
40. How would you monitor a model in production?
   - Hint: track prediction distributions, input feature drift, accuracy degradation, logs/alerts.
41. Describe model versioning and rollback strategies.
   - Hint: snapshot model and data, A/B testing, canary deployments.

## 12) Coding & Practical Questions

42. Implement gradient descent for linear regression (explain steps).
   - Hint: compute gradients, update weights, convergence criteria.
43. Given an imbalanced dataset, how would you handle it?
   - Hint: resampling, class weights, anomaly detection framing, appropriate metrics.
44. How to handle missing data?
   - Hint: imputation (mean/median/mode), modeling missingness, using indicators.

## 13) Math & Theory

45. Explain eigenvalues and eigenvectors and where they appear in ML.
   - Hint: PCA, spectral clustering.
46. What is SVD and how is it related to PCA?
   - Hint: matrix factorization, low-rank approximation.

## 14) System Design for ML

47. Design a recommendation system (high-level components).
   - Hint: data collection, candidate generation, ranking, online features, feedback loop.
48. How would you build a real-time fraud detection system?
   - Hint: streaming ingestion, feature engineering, scoring, alerting, latency constraints.

## 15) Behavioral / Soft Questions

49. Describe a time you improved a model's performance.
50. How do you prioritize features/experiments when resources are limited?

---

## Contributing

- Add full answers, diagrams, or code examples under each question.
- Create separate files for long-form answers (e.g., `answers/01_fundamentals.md`) and link from this file.
- Label contributions with `hacktoberfest` or follow the repo maintainers' preferred labeling.

---

If you'd like to be assigned this issue for Hacktoberfest2025, reply on the issue (or leave a comment below) with this message (replace with your GitHub handle):

```
Hi @DHEERAJHARODE, I'd like to be assigned this issue for Hacktoberfest2025. My GitHub handle is @your-github-username. I'll add detailed answers and code samples for AI/ML interview questions.
```

Thank you — happy contributing! 🚀

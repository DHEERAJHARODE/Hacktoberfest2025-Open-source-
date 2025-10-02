import numpy as np
import matplotlib.pyplot as plt
from typing import List, Tuple

class KMeansClustering:
    def __init__(self, k: int, max_iters: int = 100):
        """
        Initialize K-Means clustering algorithm
        
        Parameters:
        -----------
        k : int
            Number of clusters
        max_iters : int
            Maximum number of iterations for the algorithm
        """
        self.k = k
        self.max_iters = max_iters
        self.centroids = None
        self.labels = None
    
    def fit(self, X: np.ndarray) -> None:
        """
        Fit K-Means clustering to the data
        
        Parameters:
        -----------
        X : np.ndarray
            Input data of shape (n_samples, n_features)
        """
        # Randomly initialize centroids
        n_samples, n_features = X.shape
        idx = np.random.choice(n_samples, self.k, replace=False)
        self.centroids = X[idx]
        
        # Main K-Means loop
        for _ in range(self.max_iters):
            # Assign points to nearest centroid
            old_centroids = self.centroids.copy()
            self.labels = self._assign_clusters(X)
            
            # Update centroids
            self._update_centroids(X)
            
            # Check for convergence
            if np.allclose(old_centroids, self.centroids):
                break
    
    def _assign_clusters(self, X: np.ndarray) -> np.ndarray:
        """
        Assign each data point to the nearest centroid
        
        Parameters:
        -----------
        X : np.ndarray
            Input data
            
        Returns:
        --------
        np.ndarray
            Cluster assignments for each point
        """
        # Calculate distances between each point and all centroids
        distances = np.sqrt(((X - self.centroids[:, np.newaxis])**2).sum(axis=2))
        return np.argmin(distances, axis=0)
    
    def _update_centroids(self, X: np.ndarray) -> None:
        """
        Update centroid positions based on mean of assigned points
        
        Parameters:
        -----------
        X : np.ndarray
            Input data
        """
        for k in range(self.k):
            if np.any(self.labels == k):
                self.centroids[k] = X[self.labels == k].mean(axis=0)
    
    def predict(self, X: np.ndarray) -> np.ndarray:
        """
        Predict cluster labels for new data
        
        Parameters:
        -----------
        X : np.ndarray
            Input data
            
        Returns:
        --------
        np.ndarray
            Predicted cluster labels
        """
        return self._assign_clusters(X)

def generate_sample_data(n_samples: int = 300) -> np.ndarray:
    """
    Generate sample data for clustering
    
    Parameters:
    -----------
    n_samples : int
        Number of samples to generate
        
    Returns:
    --------
    np.ndarray
        Generated sample data
    """
    np.random.seed(42)
    
    # Generate three clusters
    n_samples_per_cluster = n_samples // 3
    
    cluster1 = np.random.normal(loc=[0, 0], scale=0.5, size=(n_samples_per_cluster, 2))
    cluster2 = np.random.normal(loc=[2, 2], scale=0.5, size=(n_samples_per_cluster, 2))
    cluster3 = np.random.normal(loc=[0, 2], scale=0.5, size=(n_samples_per_cluster, 2))
    
    return np.vstack([cluster1, cluster2, cluster3])

def plot_clusters(X: np.ndarray, labels: np.ndarray, centroids: np.ndarray) -> None:
    """
    Plot the clusters and their centroids
    
    Parameters:
    -----------
    X : np.ndarray
        Input data
    labels : np.ndarray
        Cluster assignments
    centroids : np.ndarray
        Cluster centroids
    """
    plt.figure(figsize=(10, 6))
    plt.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis')
    plt.scatter(centroids[:, 0], centroids[:, 1], c='red', marker='x', s=200, linewidths=3)
    plt.title('K-Means Clustering Results')
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.show()

def main():
    # Generate sample data
    X = generate_sample_data()
    
    # Initialize and fit K-Means
    kmeans = KMeansClustering(k=3)
    kmeans.fit(X)
    
    # Plot results
    plot_clusters(X, kmeans.labels, kmeans.centroids)
    
    # Print cluster information
    for i in range(kmeans.k):
        cluster_size = np.sum(kmeans.labels == i)
        print(f"Cluster {i}: {cluster_size} points")
        print(f"Centroid {i}: {kmeans.centroids[i]}\n")

if __name__ == "__main__":
    main()
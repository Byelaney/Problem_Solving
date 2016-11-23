// Add your code here
  public Difference(int[] elements) {
      this.elements = elements;
  }

  public void computeDifference() {
      int max = -2147483648;
      int min = 2147483647;
      for (int i = 0;i<elements.length;++i) {
          if (elements[i] > max)
              max = elements[i];
          if (elements[i] < min)
              min = elements[i];
      }
      this.maximumDifference = max - min;
  }

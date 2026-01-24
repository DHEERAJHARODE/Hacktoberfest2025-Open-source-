public String minimizeStringValue(String s) {
    int[] cnt = new int[26];
    for (char c : s.toCharArray()) {
        if (c != '?') {
            cnt[c - 'a']++;
        }
    }

    char[] result = s.toCharArray();
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        if (result[i] == '?') {
            while (cnt[j] > 0) {
                j++;
            }
            result[i] = (char) ('a' + j);
            cnt[j]++;
        }
    }

    return new String(result);
}